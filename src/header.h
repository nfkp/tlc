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

public:
	SunVoxGD();

	void SV_load(String path);
	void SV_lock_slot();
	void SV_unlock_slot();
	void SV_volume(const int level);
	void SV_play();
	void SV_stop();
	void SV_pattern_mute(String name, int mute);
	void SV_rewind(const int line_num);
	void SV_pause();
	void SV_resume();
	void SV_play_from_beginning();
};

}

#endif