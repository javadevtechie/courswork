<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<CodeBlocks_project_file>
	<FileVersion major="1" minor="6" />
	<Project>
		<Option title="TheaterBookingSystem" />
		<Option pch_mode="2" />
		<Option compiler="gcc" />
		<Build>
			<Target title="Debug">
				<Option output="bin/Debug/TheaterBookingSystem" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Debug/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-g" />
					<Add directory="include" />
					<Add directory="./" />
					<Add directory="src" />
				</Compiler>
			</Target>
			<Target title="Release">
				<Option output="bin/Release/TheaterBookingSystem" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Release/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-O2" />
					<Add directory="include" />
					<Add directory="./" />
					<Add directory="src" />
				</Compiler>
				<Linker>
					<Add option="-s" />
				</Linker>
			</Target>
		</Build>
		<Compiler>
			<Add option="-Wall" />
			<Add option="-fexceptions" />
		</Compiler>
		<Unit filename="src/Film.cpp" />
		<Unit filename="include/Film.h" />
		<Unit filename="include/Event.h" />
		<Unit filename="include/LiveMusic.h" />
		<Unit filename="main.cpp" />
		<Unit filename="src/Event.cpp" />
		<Unit filename="src/LiveMusic.cpp" />
		<Extensions>
			<lib_finder disable_auto="1" />
		</Extensions>
	</Project>
</CodeBlocks_project_file>
