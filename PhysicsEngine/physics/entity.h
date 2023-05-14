#ifndef _entity_h
#define _entity_h

#include "rigidbody.h"

/// <summary>
/// ʵ�壬�����е�����
/// </summary>
typedef struct entity
{
	Rigidbody* body;
	/// <summary>
	/// �����ɫ
	/// </summary>
	string fillerColor;
	/// <summary>
	/// ������ɫ
	/// </summary>
	string outlineColor;
}Entity;

/// <summary>
/// ��ʼ��ʵ��
/// </summary>
Entity* InitEntity(Rigidbody* body, Vector position);

Entity* CreateCircleEntity(Vector position, double radius, double density,
	bool isStatic, double restitution);

Entity* CreateBoxEntity(Vector position, double width, double height,
	double density, bool isStatic, double restitution);

Entity* CreatePolygonEntity(Vector* vertices, int num, double density,
	bool isStatic, double restitution);

void ChangeColor(Entity* entity, string fillerColor, string outlineColor);

/// <summary>
/// ����
/// </summary>
void DrawEntity(Entity entity);
#endif