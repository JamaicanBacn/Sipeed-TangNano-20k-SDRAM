
VFLAGS =  --cc --exe --build --trace-fst

TESTMOD =SDRAM
OBJDIR  =$(CURDIR)/TestBenches/$(TESTMOD)/obj_dir
COMPDIR =$(CURDIR)/CompilationLists
RTL 	=$(COMPDIR)/$(TESTMOD)/rtl.f
CPP		=$(COMPDIR)/$(TESTMOD)/cpp.f


sdram:
	verilator $(VFLAGS) --Mdir $(OBJDIR) --top-module $(TESTMOD) -f $(RTL) -f $(CPP) 