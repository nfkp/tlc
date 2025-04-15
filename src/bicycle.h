#ifndef BICYCLE_H
#define BICYCLE_H

#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Bicycle : public Area3D {
	GDCLASS(Bicycle, Area3D)

protected:
	static void _bind_methods();
	void _notification(int p_what);

private:
	Vector3 center;
	double time = 0.;
	double delta = 0.;

public:
	Bicycle();
	void _process(double delta) override;
};

}

#endif
