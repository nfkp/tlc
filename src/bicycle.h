#ifndef BICYCLE_H
#define BICYCLE_H

#include <godot_cpp/classes/vehicle_body3d.hpp>

namespace godot {

class Bicycle : public VehicleBody3D {
	GDCLASS(Bicycle, VehicleBody3D)

protected:
	static void _bind_methods();
	//void _notification(int p_what);

private:
	void end_function();

public:
	Bicycle();
};

}

#endif
