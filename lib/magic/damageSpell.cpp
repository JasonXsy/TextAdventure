#include "magic/damageSpell.h"

DamageSpell::DamageSpell( int manaCost, int minimiumLevel, std::string name, std::shared_ptr<Formula> formula ) 
		: Spell( manaCost, minimiumLevel, name, formula ) {
}

DamageSpell::~DamageSpell() {

}

void DamageSpell::castSpell( User *caster, Entity *target ) {
    std::cout << "casting damage spell" << std::endl;

	int damage = getFormula()->calculateValue( caster );
	caster->notifySession( "you cast " + getName() + " dealing " + to_string( damage ) + " damage" );

	target->damage( damage );
}
