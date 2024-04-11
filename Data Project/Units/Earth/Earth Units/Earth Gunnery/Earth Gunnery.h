#ifndef EarthGunnery_H
#define EarthGunnery_H

#include "../../Earth Unit/Earth Unit.h"
#include <algorithm>

class EarthGunnery : public EarthUnit {
private:
	/* The weight of the health */
	double HealthWeight; 
	/* The weight of the power */
	double PowerWeight;

	/**
  * Calculates the weighting factor based on the value and weight.
  * @param {double} value - The value to calculate the weighting factor for.
  * @param {double} weight - The weight to be applied to the value.
  * @returns {double} The weighting factor.
  */
	double CalculateWeight(double Value, double Weight) {
		const double MaxValue = std::max(Value, Weight);

		return Value / MaxValue * Weight;
	}
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
	double GetPriority();

};

#endif // !EarthGunnery_H
