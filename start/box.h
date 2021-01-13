
#ifndef BOX_H
#define BOX_H

#include <rt2d/entity.h>

 /// @brief The Shape class is the Entity implementation.
class Box : public Entity
{
public:
	/// @brief Constructor
	Box();
	/// @brief Destructor
	virtual ~Box();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* BOX_H */
