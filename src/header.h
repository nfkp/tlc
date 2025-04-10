#ifndef SUNVOXGD_H
#define SUNVOXGD_H

#include <godot_cpp/classes/node.hpp>
#include "sunvox.h"

namespace godot {

class SunVoxGD : public Node {
	GDCLASS(SunVoxGD, Node)

protected:
	static void _bind_methods();
	void _notification(int p_what);

private:
	void end_function();
	int m_volume;

public:
	SunVoxGD();
	~SunVoxGD();

	void SV_load(String path);
	void SV_volume(const int level);
	void SV_play();
	void SV_stop();
};

}

#endif