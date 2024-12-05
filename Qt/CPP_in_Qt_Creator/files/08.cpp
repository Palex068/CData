#include "spaceobject.h"  // Подключение заголовочного файла

SpaceObject::SpaceObject(SpaceCoords coords,
                         double mass) {  // Описание тела конструктора
  // coords(coords),  // Инициализация координат
  // mass(mass);      // Инициализация массы
}

double SpaceObject::get_mass() {  // Объявление тела Геттера
  return this->mass;  // Возврат значения массы через указатель this
}

double SpaceObject::set_mass(double new_mass) {  // Объявление тела сеттера
  return this->mass = new_mass;  // Присвоение нового значения и возврат его
}

SpaceObject::SpaceCoords SpaceObject::get_coords() { return this->coords; }

SpaceObject::SpaceCoords SpaceObject::set_coords(SpaceCoords new_coords) {
  return this->coords = new_coords;
}

SpaceObject::~SpaceObject() {}