#include "./includes/Ice.hpp"
#include "./includes/Cure.hpp"
#include "./includes/Character.hpp"

int main(void)
{
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	Character jorge("Jorge");
	Character xialiong("Xialiong");

	jorge.equip(ice);
	jorge.equip(cure);
	jorge.equip(ice);
	jorge.use(0, xialiong);
	jorge.use(2, xialiong);

	return (0);
}