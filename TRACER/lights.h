#pragma once

class Light
{
	std::string name;

public:
	float32 intensity;
	Light(float32 _intensity, const char * _name) : intensity(_intensity), name(_name) {}
	
	virtual std::string getName() { return name; }
	virtual vec3 getVec() = 0;
};

class Ambient : public Light
{
public:
	Ambient(float32 _intensity) : Light(_intensity, "Ambient") {}

	vec3 getVec() override
	{
		return vec3();
	}
};

class Directional : public Light
{
public:
	vec3 direction;

	Directional(float32 _intensity, vec3 _direction) : Light(_intensity, "Directional"), direction(_direction)  {}

	vec3 getVec() override
	{
		return direction;
	}
};

class Point : public Light
{
public:
	vec3 position;

	Point(float32 _intensity, vec3 _position) : Light(_intensity, "Point"), position(_position) {}

	vec3 getVec() override
	{
		return position;
	}
};
