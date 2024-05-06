#ifndef EarthGunnery_H
#define EarthGunnery_H

#include "../../Earth Unit/Earth Unit.h"
#include <algorithm>

class GameManager;
class EarthGunnery : public EarthUnit
{
private:
	/* The weight of the health */
	double HealthWeight;
	/* The weight of the power */
	double PowerWeight;

public:
	/**
	 * Constructor for EarthGunnery class
	 * @param {int} ID - The ID of the EarthGunnery
	 * @param {double} Health - The health of the EarthGunnery
	 * @param {int} Power - The power of the EarthGunnery
	 * @param {int} AttackCapacity - The attack capacity of the EarthGunnery
	 * @param {int} JoinTime - The join time of the EarthGunnery
	 */
	EarthGunnery(int ID, double Health, int Power, int AttackCapacity, int JoinTime);

	/**
	 * Returns the priority of the EarthGunnery
	 * @returns {double} The priority of the EarthGunnery
	 */
	double GetPriority() const;

	virtual void Attack(GameManager *Game, bool Interactive = true);
};

#endif // !EarthGunnery_H
