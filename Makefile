OBJ = obj/main.o obj/Window.o obj/Game.o obj/Model.o obj/FileReader.o obj/Shapes.o obj/ShaderProgram.o obj/Camera.o obj/utils.o obj/WorldObject.o
INC_PATH = -I src/include

bin/game : $(OBJ) 
	g++ -std=c++17 $(INC_PATH) -o bin/game $(OBJ) -lGL -lGLEW -lglfw 

obj/%.o : src/%.cpp
	g++ -c $(INC_PATH) -o $@ $<

clean:
	rm -r obj/ bin/
	mkdir obj/ bin/