# Regla para testNode
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

# Regla para testListArray
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

# Regla para ListLinked
bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h

# Regla para Point2D
bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

# Regla para Shape
Shape.o: Shape.h Shape.cpp

	g++ -c Shape.cpp

# Regla para Circle
Circle.o: Circle.h Circle.cpp Shape.h Point2D.h
	g++ -c Circle.cpp

# Regla para testCircle
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testCircle testCircle.cpp Circle.o Shape.o Point2D.o

# Regla para Rectangle
Rectangle.o: Rectangle.h Rectangle.cpp Shape.h Point2D.h
	g++ -c Rectangle.cpp

# Regla para testRectangle
bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o Point2D.o

# Regla para Square
Square.o: Square.h Square.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

# Regla para testSquare
bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o

# Regla para Drawing
Drawing.o: Drawing.h Drawing.cpp List.h ListArray.h Shape.h
	g++ -c Drawing.cpp

# Regla para testDrawing
bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

clean:
	rm -r *.o *.gch bin
