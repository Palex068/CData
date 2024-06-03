OUT = s21_matrix_oop.a
OUT_DIR = build
TEST = test

all: $(OUT) $(TEST)

$(OUT):
	mkdir -p $(OUT_DIR)
	cmake . -B $(OUT_DIR)
	$(MAKE) -C $(OUT_DIR) s21_matrix_oop

$(TEST): $(OUT)
	$(MAKE) -C $(OUT_DIR) tests

clean:
	rm -rf $(OUT_DIR)
