##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=web1
ConfigurationName      :=Debug
WorkspacePath          :=D:/WorkSpace
ProjectPath            :=D:/WorkSpace/web1
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lekha
Date                   :=01/04/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="web1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/supplemental.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/DecimalIP.cpp$(ObjectSuffix) $(IntermediateDirectory)/BinaryIP.cpp$(ObjectSuffix) $(IntermediateDirectory)/IPAddress.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/supplemental.cpp$(ObjectSuffix): supplemental.cpp $(IntermediateDirectory)/supplemental.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/WorkSpace/web1/supplemental.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/supplemental.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/supplemental.cpp$(DependSuffix): supplemental.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/supplemental.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/supplemental.cpp$(DependSuffix) -MM supplemental.cpp

$(IntermediateDirectory)/supplemental.cpp$(PreprocessSuffix): supplemental.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/supplemental.cpp$(PreprocessSuffix) supplemental.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/WorkSpace/web1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/DecimalIP.cpp$(ObjectSuffix): DecimalIP.cpp $(IntermediateDirectory)/DecimalIP.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/WorkSpace/web1/DecimalIP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DecimalIP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DecimalIP.cpp$(DependSuffix): DecimalIP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DecimalIP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DecimalIP.cpp$(DependSuffix) -MM DecimalIP.cpp

$(IntermediateDirectory)/DecimalIP.cpp$(PreprocessSuffix): DecimalIP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DecimalIP.cpp$(PreprocessSuffix) DecimalIP.cpp

$(IntermediateDirectory)/BinaryIP.cpp$(ObjectSuffix): BinaryIP.cpp $(IntermediateDirectory)/BinaryIP.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/WorkSpace/web1/BinaryIP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BinaryIP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BinaryIP.cpp$(DependSuffix): BinaryIP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BinaryIP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BinaryIP.cpp$(DependSuffix) -MM BinaryIP.cpp

$(IntermediateDirectory)/BinaryIP.cpp$(PreprocessSuffix): BinaryIP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BinaryIP.cpp$(PreprocessSuffix) BinaryIP.cpp

$(IntermediateDirectory)/IPAddress.cpp$(ObjectSuffix): IPAddress.cpp $(IntermediateDirectory)/IPAddress.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/WorkSpace/web1/IPAddress.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IPAddress.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IPAddress.cpp$(DependSuffix): IPAddress.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IPAddress.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IPAddress.cpp$(DependSuffix) -MM IPAddress.cpp

$(IntermediateDirectory)/IPAddress.cpp$(PreprocessSuffix): IPAddress.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IPAddress.cpp$(PreprocessSuffix) IPAddress.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


