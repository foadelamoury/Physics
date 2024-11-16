#include "Collider.h"

bool Collider::checkCollision(Collider other)
{
	//cout << (other.center - center).getMagnitude()<<" " << (other.r + r)<< endl;
	return (other.center - center).getMagnitude() < (other.r + r);
}
