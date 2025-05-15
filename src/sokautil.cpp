#include "include/sokautil.h"

void VelocityLogic::increase_by(double value, double delta) {
	m_vel += value * delta;
	m_dist += m_vel * delta;
}

double VelocityLogic::get_velocity() const {
	return m_vel;
}

double VelocityLogic::get_distance() const {
	return m_dist;
}

bool SokaBoolTracker::just_happened(const bool value) {
	const bool out = value != last_frame;
	last_frame = value;
	return out;
}