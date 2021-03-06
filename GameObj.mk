##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GameObj
ConfigurationName      :=Debug
WorkspacePath          :=/home/xemyst/Documents/projectes/Robotica/GameObj
ProjectPath            :=/home/xemyst/Documents/projectes/Robotica/GameObj
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=xemyst
Date                   :=18/09/18
CodeLitePath           :=/home/xemyst/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GameObj.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Golero.cpp$(ObjectSuffix) $(IntermediateDirectory)/Atacante.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Robo.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemigo.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameObj.cpp$(ObjectSuffix) $(IntermediateDirectory)/Defensor.cpp$(ObjectSuffix) $(IntermediateDirectory)/FieldPoint.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Golero.cpp$(ObjectSuffix): Golero.cpp $(IntermediateDirectory)/Golero.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Golero.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Golero.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Golero.cpp$(DependSuffix): Golero.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Golero.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Golero.cpp$(DependSuffix) -MM Golero.cpp

$(IntermediateDirectory)/Golero.cpp$(PreprocessSuffix): Golero.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Golero.cpp$(PreprocessSuffix) Golero.cpp

$(IntermediateDirectory)/Atacante.cpp$(ObjectSuffix): Atacante.cpp $(IntermediateDirectory)/Atacante.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Atacante.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Atacante.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Atacante.cpp$(DependSuffix): Atacante.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Atacante.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Atacante.cpp$(DependSuffix) -MM Atacante.cpp

$(IntermediateDirectory)/Atacante.cpp$(PreprocessSuffix): Atacante.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Atacante.cpp$(PreprocessSuffix) Atacante.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Robo.cpp$(ObjectSuffix): Robo.cpp $(IntermediateDirectory)/Robo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Robo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Robo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Robo.cpp$(DependSuffix): Robo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Robo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Robo.cpp$(DependSuffix) -MM Robo.cpp

$(IntermediateDirectory)/Robo.cpp$(PreprocessSuffix): Robo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Robo.cpp$(PreprocessSuffix) Robo.cpp

$(IntermediateDirectory)/Enemigo.cpp$(ObjectSuffix): Enemigo.cpp $(IntermediateDirectory)/Enemigo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Enemigo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemigo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemigo.cpp$(DependSuffix): Enemigo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemigo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemigo.cpp$(DependSuffix) -MM Enemigo.cpp

$(IntermediateDirectory)/Enemigo.cpp$(PreprocessSuffix): Enemigo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemigo.cpp$(PreprocessSuffix) Enemigo.cpp

$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix): Bola.cpp $(IntermediateDirectory)/Bola.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Bola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bola.cpp$(DependSuffix): Bola.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bola.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bola.cpp$(DependSuffix) -MM Bola.cpp

$(IntermediateDirectory)/Bola.cpp$(PreprocessSuffix): Bola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bola.cpp$(PreprocessSuffix) Bola.cpp

$(IntermediateDirectory)/GameObj.cpp$(ObjectSuffix): GameObj.cpp $(IntermediateDirectory)/GameObj.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/GameObj.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameObj.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameObj.cpp$(DependSuffix): GameObj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameObj.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameObj.cpp$(DependSuffix) -MM GameObj.cpp

$(IntermediateDirectory)/GameObj.cpp$(PreprocessSuffix): GameObj.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameObj.cpp$(PreprocessSuffix) GameObj.cpp

$(IntermediateDirectory)/Defensor.cpp$(ObjectSuffix): Defensor.cpp $(IntermediateDirectory)/Defensor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/Defensor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Defensor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Defensor.cpp$(DependSuffix): Defensor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Defensor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Defensor.cpp$(DependSuffix) -MM Defensor.cpp

$(IntermediateDirectory)/Defensor.cpp$(PreprocessSuffix): Defensor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Defensor.cpp$(PreprocessSuffix) Defensor.cpp

$(IntermediateDirectory)/FieldPoint.cpp$(ObjectSuffix): FieldPoint.cpp $(IntermediateDirectory)/FieldPoint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/xemyst/Documents/projectes/Robotica/GameObj/FieldPoint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FieldPoint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FieldPoint.cpp$(DependSuffix): FieldPoint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FieldPoint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FieldPoint.cpp$(DependSuffix) -MM FieldPoint.cpp

$(IntermediateDirectory)/FieldPoint.cpp$(PreprocessSuffix): FieldPoint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FieldPoint.cpp$(PreprocessSuffix) FieldPoint.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


