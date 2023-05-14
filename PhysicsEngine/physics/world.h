#ifndef _world_h
#define _world_h

#include "rigidbody.h"
#include "manifold.h"

double GetMinBodySize();
double GetMaxBodySize();
double GetMinDensity();
double GetMaxDensity();

void InitWorld();
Vector GetGravity();
void AddBody(Rigidbody* body);
bool RemoveBody(int index);
Rigidbody* GetBody(int index);
int GetBodyCount();

/// <summary>
/// �����������
/// </summary>
/// <param name="time">ÿ֡ʱ��</param>
/// <param name="iterations">����������Խ��Խ��ȷ</param>
void Step(double time, unsigned int iterations);
void BroadPhase();
void NarrowPhase();
void StepBodies(double time, int iterations);
/// <summary>
/// ������������
/// </summary>
/// <param name="mtv">: minimum translation vector</param>
void SeparateBodies(Rigidbody* bodyA, Rigidbody* bodyB, Vector mtv);
/// <summary>
/// ������ײ
/// </summary>
void ResolveCollisionWithFriction(Manifold contact);

#endif
