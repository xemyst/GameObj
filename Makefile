.PHONY: clean All

All:
	@echo "----------Building project:[ GameObj - Debug ]----------"
	@"$(MAKE)" -f  "GameObj.mk"
clean:
	@echo "----------Cleaning project:[ GameObj - Debug ]----------"
	@"$(MAKE)" -f  "GameObj.mk" clean
