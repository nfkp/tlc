#ifndef BICYCLE_H
#define BICYCLE_H

#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include "include/sokautil.h"

namespace godot {

class Bicycle : public Node3D {
	GDCLASS(Bicycle, Node3D)

protected:
	static void _bind_methods();
	void _notification(int p_what);

private:
	Vector3 center;
	double time = 0;
	double delta = 0;
	VelocityLogic translation[3];
	VelocityLogic z_rotation;

public:
	void _process(double delta) override;
};

}

#endif
