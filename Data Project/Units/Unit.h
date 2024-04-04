#ifndef Unit_H
#define Unit_H

class Unit {
protected:
	/// Base properties for all units
	/* The unit's unique ID*/
	const int ID;
	/* The unit's attack capacity */
	int AttackCapacity;
	/* The unit's health */
	double Health;
	/* The unit's power */
	int Power;
	/// To-Do: Add Time & Delay properties

	/* The timestep at which the unit joined the battle */
	int JoinTime;
	/* The total time the unit spends in battle */
	int BattleTime;
public:
	Unit(int ID, int AttackCapacity, double Health, int Power, int JoinTime) :
		ID(ID), AttackCapacity(AttackCapacity), Health(Health), Power(Power), JoinTime(JoinTime) {}

	int GetPower() const {
		return this->Power;
	}

	int GetID() const {
		return this->ID;
	}

	int GetJoinTime() const {
		return this->JoinTime;
	}

	double GetHealth() const {
		return this->Health;
	}
	
	void SetHealth(int NewHealth) {
		this->Health = NewHealth;
	}

	/*virtual void Print() = 0;

	virtual bool Remove(int ID) = 0;*/
};

#endif // !Unit_H