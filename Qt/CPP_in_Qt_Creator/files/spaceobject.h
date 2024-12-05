#ifndef SPACEOBJECT_Н  // Если не определено
#define SPACEOBJECT_Н  // Определить

class SpaceObject  // Название класса
{         // Начало области видимости класса
 public:  // К структуре открыт доступ извне класса
  struct SpaceCoords {  // Объявление структуры космических координат
    double р;           // Координата ”p”
    double Ь;           // Координата ”b”
    double i;           // Координата ”i”
  };                    // Конец объявления структуры
  SpaceObject(SpaceCoords coords, double mass);  // Объявление конструктора
  ~SpaceObject();  // Объявление деструктора

  SpaceCoords coords;  // Объявление поля координаты внутри класса
  double mass;  // Объявление поля массы внутри класса
  double get_mass();  // Объявление Геттера (от англ. get - получить) -
                      // позволяет получить значение, но не изменять
  double set_mass(
      double new_mass);  // Объявление Сеттера (от англ. set - установить) -
                         // позволяет установить значение
  SpaceCoords get_coords();  // Объявление Геттера координат
  SpaceCoords set_coords(
      SpaceCoords new_coords);  // Объявление Сеттера координат
};      // Конец области видимости класса
#endif  // SPACEOBJECT_Н //Если условие выполнилось - сохранить, если не
        // выполнить, вырезать с #ifndef по текущую команду #endif)