#pragma once

#include <otf2/otf2.h>

#include <map>
#include <vector>

class TreeRegion
{
public:
    TreeRegion(OTF2_StringRef _name, size_t _start, TreeRegion* _parent);
    TreeRegion& add_child(OTF2_StringRef _name, size_t _start);
    TreeRegion& get_child(int index);
    bool is_open() const;
    void set_end(size_t _end);
    size_t get_duration() const;
    size_t get_start() const;
    size_t get_end() const;
    OTF2_StringRef get_name() const;
    size_t get_number_of_children() const;
    void set_parent(TreeRegion* _parent);
    TreeRegion* get_parent() const;

protected:
    OTF2_StringRef name;
    size_t start, end;
    TreeRegion* parent;
    std::vector<TreeRegion> children;
};

class TreeLocation : public TreeRegion
{
public:
    TreeLocation();
    TreeLocation(OTF2_LocationRef _id, OTF2_StringRef name, size_t global_offset);
    TreeRegion* get_cursor();
    void set_cursor(TreeRegion* node);

private:
    OTF2_LocationRef id;
    TreeRegion* cursor;
};

class TreeLocationGroup
{
public:
    TreeLocationGroup();
    explicit TreeLocationGroup(OTF2_LocationGroupRef _id);
    TreeLocationGroup filter_closed_regions();
    void set_cursors_to_last_open_regions();
    void update_parents();
    void set_id(OTF2_LocationGroupRef _id);
    void set_name(OTF2_StringRef _name);
    OTF2_LocationGroupRef get_id() const;
    OTF2_StringRef get_name_ref() const;
    TreeLocation& add_child(OTF2_LocationRef id, OTF2_StringRef name, size_t global_offset);
    TreeLocation& get_location(OTF2_LocationRef location);
    size_t get_number_of_locations() const;
    void clear();

private:
    OTF2_LocationGroupRef id;
    OTF2_StringRef name;
    std::map<OTF2_LocationRef, TreeLocation> locations;
};