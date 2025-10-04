#include "mod/MyMod.h"

#include <exception>
#include <ll/api/memory/Hook.h>
#include <ll/api/service/Bedrock.h>
#include <mc/deps/core/math/Vec3.h>
#include <mc/legacy/ActorUniqueID.h>
#include <mc/world/actor/Actor.h>
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/BlockSource.h>
#include <mc/world/level/Explosion.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/block/Block.h>
#include <mc/world/level/block/actor/BlockActor.h>

namespace lk {
LL_TYPE_INSTANCE_HOOK(ExplodeHook, HookPriority::High, Explosion, &Explosion::explode, bool, ::IRandom& random) {
    try {
        // 神秘bug
        if (mRegion.getDimensionId().id == 0) {
            mBreaking = false;
            mFire     = false;
        }
        return origin(random);
    } catch (std::exception) {
        return origin(random);
    }
}

void hook() { ExplodeHook::hook(); }
} // namespace lk