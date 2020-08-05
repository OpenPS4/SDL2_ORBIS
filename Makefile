ifndef ORBISDEV
$(error ORBISDEV, is not set)
endif

target := ps4_lib
OutPath := lib
TargetFile := libSDL.a

include $(ORBISDEV)/make/ps4sdklib.mk
CompilerFlags += -D__PS4__ -D__ORBIS__
IncludePath += -I$(ORBISDEV)/usr/include -I$(ORBISDEV)/usr/include/c++/v1 -I$(ORBISDEV)/usr/include/orbis

# we are just shipping a cross builted (on linux) archive here!

$(AllTarget): $(ObjectFiles)
	@echo "$(TargetFile) Compiled!"

install:
# ToDo: copy to include and lib directories
	@echo "$(TargetFile) Installed!"