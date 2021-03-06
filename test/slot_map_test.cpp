#include "common.h"
#include "slot_map.h"
#include "types.h"

#include <catch.hpp>

using namespace knight;
using namespace foundation;

struct Object {
  typedef ID32<Object>::ID ID;

  ID id;
};

TEST_CASE("Slot Map") {
  Allocator &a = memory_globals::default_allocator();
  {
    SlotMap<Object, Object::ID> slot_map(a);

    Object::ID id;
    Object *object;

    SECTION("Invalid id will return a nullptr") {
      object = slot_map.get(id);
      CHECK(object == nullptr);
    }

    id = slot_map.create();

    SECTION("Valid id will return correct object") {
      object = slot_map.get(id);

      REQUIRE(object != nullptr);
      CHECK(id == object->id);
    }

    slot_map.destroy(id);

    SECTION("Destroying object will invalidate id") {
      object = slot_map.get(id);
      CHECK(object == nullptr);
    }

    SECTION("Objects created at same index will have different versions") {
      Object::ID new_id = slot_map.create();

      CHECK(new_id != id);
      CHECK(new_id.index == id.index);
      CHECK(new_id.version == id.version + 1);
    }
  }
}
