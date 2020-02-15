#pragma once

#ifndef VSEPR_H
#define VSEPR_H

#include <string>
#include <map>
#include <vector>
#include "glm/glm.hpp"

#define SIN_45 0.70710678118654752440084436210485
#define COS_30 0.86602540378443864676372317075294
#define SIN_30 0.5
#define PERIOD_CONSTANT 0.4
#define GROUP_CONSTANT 0.8
#define UPSCALING 4
#define PI 3.14159265358979323846264338f
#define MAX_POINT_LIGHTS 36
#define smoothingConstant 0.2f

static std::map <std::string, int> numberTerms;
static bool organic;

struct Element{
	int atomicNumber;
	int valenceNumber;
	int periodNumber;
	std::string name;
	float electronegativity;
	float atomicRadius;
	float covalentRadii[3];
	float vanDerWaalsRadius;
	bool exception = false;
	glm::vec3 color;

	Element() {}

	Element(int _atomicNumber) {atomicNumber = _atomicNumber;}

	Element(int _atomicNumber, int _valenceNumber, int _periodNumber, std::string _name) {
		atomicNumber = _atomicNumber;
		valenceNumber = _valenceNumber;
		periodNumber = _periodNumber;
		name = _name;
	}

	Element(int _atomicNumber, int _valenceNumber, int _periodNumber, std::string _name, bool _exception) {
		exception = _exception;
		valenceNumber = _valenceNumber;
		periodNumber = _periodNumber;
		name = _name;
	}
};

struct BondedElement {
public:
	Element base;
	int loneElectrons;
	int bondedElectrons;
	int id = 0;
	std::vector<BondedElement> neighbours;
	glm::vec3 position;
	glm::vec3 vanDerWaalsPosition;
	glm::mat4 rotation = glm::mat4();
	int numberOfBonds;

	BondedElement(int _loneElectrons, int _bondedElectrons, Element _base) {
		uid = generateUID();
		base = _base;
		loneElectrons = _loneElectrons;
		bondedElectrons = _bondedElectrons;
		if(base.periodNumber == 1) {
			numberOfBonds = 2 - base.valenceNumber;
		}
		else {
			numberOfBonds = 8 - base.valenceNumber;
		}
		if(numberOfBonds < 1) {
			numberOfBonds = 1;
		}
	}

	BondedElement() {}

	uint32_t getUID() {
		return uid;
	}

	friend bool operator==(const BondedElement &lhs, const BondedElement &rhs) {
		return lhs.uid == rhs.uid;
	}

private:
	static uint32_t maxUID;
	uint32_t uid;

	uint32_t generateUID() {
		maxUID++;
		return maxUID;
	}
};

struct Substituent {
	std::vector<BondedElement> components;
	Substituent *parent;
	int connectionPoint;
};

extern std::vector<BondedElement> VSEPRModel;
std::vector<BondedElement> VSEPRMain();

#endif