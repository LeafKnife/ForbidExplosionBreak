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
    // 神秘bug
    auto x = mPos->x;
    auto z = mPos->z;
    if (mRegion.getDimensionId().id == 0 && x > -8000 && x < 8000 && z > -8000 && z < 8000) {
        mBreaking = false;
        mFire     = false;
    }
    return origin(random);
}

void hook() { ExplodeHook::hook(); }
} // namespace lk