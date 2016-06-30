#include "damagereductioneffect.h"
#include "core/event.h"
#include "core/object.h"

DamageReductionEffect::DamageReductionEffect(Object* parent)
    : Component(parent, 110)
    , percent_(15)
{
    ;
}
    
bool DamageReductionEffect::HandleEvent(Event& event)
{
    if(event.GetName() == "take_damage")
    {
        int32_t damage_orig  = event.GetValueAsInteger("damage");
        int32_t damage_taken = 100 * damage_orig / (percent_ + 100);
        
        printf("[DamageReductionEffect] : reduced from %d to %d\n", 
            damage_orig, damage_taken);
        event.SetValueInteger("damage", damage_taken);
    }
    return true;
}
