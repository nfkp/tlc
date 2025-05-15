#ifndef SOKAUTIL_H
#define SOKAUTIL_H

class VelocityLogic {
private:
	double m_vel = 0.0;
	double m_dist = 0.0;

public:
	void increase_by(double value, double delta);
	double get_velocity() const;
	double get_distance() const;
};

class SokaBoolTracker {
private:
    bool last_frame = false;
public:
    bool just_happened(bool value);
};

#endif
