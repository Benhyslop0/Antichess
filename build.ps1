#working in folder called output to work with build files

# Delete the output folder if it exists
rm -r output/ -Force -ErrorAction Ignore;
# Create the output folder.
mkdir output;

# Move into the output folder so that build files are saved there.
cd output;

# Compile the source files.
# Put your files to compile here.
g++ -c ../pieces.cpp ../main.cpp ../chessboard.cpp;

# Link the object files to create the executable.
# Include the same filenames here, without the "../" and with ".o" instead of ".cpp".
g++ -o main.exe main.o pieces.o chessboard.o;

# Move back up to the original directory.
cd ..;

# Run the executable.
./output/main.exe;
