#ifndef SOKAUTIL_H
#define SOKAUTIL_H

class VelocityLogic {
private:
	double m_vel = 0.0;
	double m_dist = 0.0;

public:
	void increase_by(double value, double delta);
	double get_velocity();
	double get_distance();
};

class Trigger {
private:
    double m_precision;
    bool m_bool;
public:
    double value;
	Trigger(double value, double precision);
    void retrigger();
void retrigger(double rate);
    double get_value();
    Trigger operator+(double const& obj);
    Trigger operator+(Trigger const& obj);
    Trigger operator-(double const& obj);
    Trigger operator-(Trigger const& obj);
    Trigger operator*(double const& obj);
    Trigger operator*(Trigger const& obj);
    Trigger operator/(double const& obj);
    Trigger operator/(Trigger const& obj);
};
#endif
