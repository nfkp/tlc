#include "include/sokautil.h"

void VelocityLogic::increase_by(double value, double delta) {
	m_vel += value * delta;
	m_dist += m_vel * delta;
}

double VelocityLogic::get_velocity() {
	return m_vel;
}

double VelocityLogic::get_distance() {
	return m_dist;
}

Trigger::Trigger(double p_value, double precision = 0.01) {
	m_bool = false;
	value = p_value;
	m_precision = precision;
}
void Trigger::retrigger() {
	m_bool = true;
}

Trigger Trigger::operator+(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj + value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator-(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj - value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator*(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj * value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}
Trigger Trigger::operator/(double const& obj) {
	if (m_bool) [[unlikely]] {
		Trigger t(obj / value);
		m_bool = false;
		return t;
	}
	Trigger n(value);
	return n;
}