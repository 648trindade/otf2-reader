#include "OTF2CallTree.hpp"

#include <cassert>
#include <stdexcept>

// =====================================================================================================================
// TreeRegion
// =====================================================================================================================

TreeRegion::TreeRegion(OTF2_StringRef _name, size_t _start, TreeRegion* _parent)
    : name(_name)
    , start(_start)
    , end(_start)
    , parent(_parent)
{
}

TreeRegion& TreeRegion::add_child(OTF2_StringRef _name, size_t _start)
{
    return this->children.emplace_back(_name, _start, this);
}

TreeRegion& TreeRegion::get_child(int index)
{
    return this->children[index];
}

bool TreeRegion::is_open() const
{
    return this->start == this->end;
}

void TreeRegion::set_end(size_t _end)
{
    this->end = _end;
}

size_t TreeRegion::get_duration() const
{
    return this->end - this->start;
}

size_t TreeRegion::get_start() const
{
    return this->start;
}

size_t TreeRegion::get_end() const
{
    return this->end;
}

OTF2_StringRef TreeRegion::get_name() const
{
    return this->name;
}

size_t TreeRegion::get_number_of_children() const
{
    return this->children.size();
}

void TreeRegion::set_parent(TreeRegion* _parent)
{
    this->parent = _parent;
}

TreeRegion* TreeRegion::get_parent() const
{
    return this->parent;
}

// =====================================================================================================================
// TreeLocation
// =====================================================================================================================

TreeLocation::TreeLocation() : TreeRegion(0, 0, nullptr), id(0)
{
};

TreeLocation::TreeLocation(OTF2_LocationRef _id, OTF2_StringRef name, size_t global_offset)
    : TreeRegion(name, global_offset, nullptr)
    , id(_id)
{
}

TreeRegion* TreeLocation::get_cursor()
{
    return this->cursor;
}

void TreeLocation::set_cursor(TreeRegion* node)
{
    this->cursor = node;
}

// =====================================================================================================================
// TreeLocationGroup
// =====================================================================================================================

TreeLocationGroup::TreeLocationGroup()
{
}

TreeLocationGroup::TreeLocationGroup(OTF2_LocationGroupRef _id)
{
    this->set_id(_id);
}

void filter_closed_regions(TreeRegion& input_region, TreeRegion& output_region)
{
    for (int i = 0; i < input_region.get_number_of_children(); i++)
    {
        auto& child = input_region.get_child(i);
        // open regions have end time unset
        if (child.is_open())
        {
            auto& r_child = output_region.add_child(child.get_name(), child.get_start());
            filter_closed_regions(child, r_child);
        }
    }
}

TreeLocationGroup TreeLocationGroup::filter_closed_regions()
{
    TreeLocationGroup result(this->id);
    result.set_name(this->name);
    for(auto& [id, location] : this->locations)
    {
        auto& r_location = result.add_child(id, location.get_name(), location.get_start());
        ::filter_closed_regions(location, r_location);
    }
    return result;
}

TreeRegion* find_last_open_region(TreeRegion& region)
{
    for (int i = 0; i < region.get_number_of_children(); i++)
    {
        auto& child = region.get_child(i);
        if (child.is_open())
        {
            if (i == region.get_number_of_children() - 1)
                return find_last_open_region(child);
            else
                throw std::runtime_error("Region should not be open!");
        }
    }
    return &region;
}

void TreeLocationGroup::set_cursors_to_last_open_regions()
{
    for(auto& [id, location] : this->locations)
    {
        TreeRegion* last_open_region = find_last_open_region(location);
        assert (last_open_region->is_open());
        location.set_cursor(last_open_region);
    }
}

void update_parents(TreeRegion& region, TreeRegion* parent)
{
    region.set_parent(parent);
    for (int i = 0; i < region.get_number_of_children(); i++)
    {
        auto& child = region.get_child(i);
        update_parents(child, &region);
    }
}

void TreeLocationGroup::update_parents()
{
    for(auto& [id, location] : this->locations)
    {
        ::update_parents(location, nullptr);
    }
}

void TreeLocationGroup::set_id(OTF2_LocationGroupRef _id)
{
    this->id = _id;
}

void TreeLocationGroup::set_name(OTF2_StringRef _name)
{
    this->name = _name;
}

OTF2_LocationGroupRef TreeLocationGroup::get_id() const
{
    return this->id;
}

OTF2_StringRef TreeLocationGroup::get_name_ref() const
{
    return this->name;
}

TreeLocation& TreeLocationGroup::add_child(OTF2_LocationRef id, OTF2_StringRef name, size_t global_offset)
{
    this->locations[id] = TreeLocation(id, name, global_offset);
    this->locations[id].set_cursor(reinterpret_cast<TreeRegion*>(&this->locations[id]));
    return this->locations[id];
}

TreeLocation& TreeLocationGroup::get_location(OTF2_LocationRef location)
{
    return this->locations[location];
}

size_t TreeLocationGroup::get_number_of_locations() const
{
    return this->locations.size();
}

void TreeLocationGroup::clear()
{
    this->id = 0;
    this->locations.clear();
}