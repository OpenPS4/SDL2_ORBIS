ifndef ORBISDEV
$(error ORBISDEV, is not set)
endif

projectname := SDL2
target := ps4_lib
OutPath := lib
TargetFile := lib$(projectname).a

include $(ORBISDEV)/make/ps4sdklib.mk
CompilerFlags += -D__PS4__ -D__ORBIS__
IncludePath += -I$(ORBISDEV)/usr/include -I$(ORBISDEV)/usr/include/c++/v1 -I$(ORBISDEV)/usr/include/orbis

# we are just shipping a cross builted (on linux) archive here!

$(AllTarget): $(ObjectFiles)
	$(dirp)
	$(archive)
	@echo "$(TargetFile) Compiled!"

install:
	@mkdir $(ORBISDEV)/usr/include/$(projectname)
	@cp source/*.h $(ORBISDEV)/usr/include/$(projectname)
	@cp lib/$(TargetFile) $(ORBISDEV)/usr/lib
	@echo "$(TargetFile) Installed!"