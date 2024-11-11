/*
#include <iostream>
#include <string.h>

class CartData {
  unsigned long id;
  char name[100];
  unsigned price;
  double weight;

public:
  // возвращает через ссылки перечисленные поля
  void get_data(unsigned long &id, unsigned &price, double &weight) {
    id = this->id;
    price = this->price;
    weight = this->weight;
  }
  // возвращает наименование товара (поле name)
  char *get_name() { return name; }

  // заносит в перечисленные поля переданные значения
  void set_data(unsigned long id, const char *name, unsigned price,
                double weight) {
    this->id = id;
    strcpy(this->name, name);
    this->price = price;
    this->weight = weight;
  }
};
int main(void) {
  CartData item;
  item.set_data(10, "Toy", 2000, 5.45);

  // __ASSERT_TESTS__
  return 0;
}
*/
