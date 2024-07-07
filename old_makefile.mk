objs = perf_sim.o cachesim.o cfg.o csrs.o extension.o disasm.o isa_parser.o processor.o triggers.o rom.o vector_unit.o mmu.o jtag_dtm.o extensions.o \
		remote_bitbang.o devices.o dts.o debug_module.o interactive.o sim.o insns/add.o insns/addi.o \
		decoder.o scoreboard.o fetch.o execute.o
		fdt.o  fdt_addresses.o  fdt_empty_tree.o  fdt_overlay.o  fdt_ro.o  fdt_rw.o  fdt_strerror.o  fdt_sw.o  fdt_wip.o \
		context.o device.o dtm.o dummy.o elfloader.o htif.o htif_hexwriter.o htif_pthread.o memif.o option_parser.o rfb.o syscall.o term.o tsi.o \
		softfloat/bf16_to_f32.o            softfloat/f16_to_f64.o            softfloat/f64_eq.o                 softfloat/s_approxRecip_1Ks.o        softfloat/s_roundPackToBF16.o \
	softfloat/f128_add.o               softfloat/f16_to_i16.o            softfloat/f64_eq_signaling.o       softfloat/s_commonNaNToF128UI.o      softfloat/s_roundPackToF128.o \
	softfloat/f128_classify.o          softfloat/f16_to_i32.o            softfloat/f64_isSignalingNaN.o     softfloat/s_commonNaNToF16UI.o       softfloat/s_roundPackToF16.o \
	softfloat/f128_div.o               softfloat/f16_to_i32_r_minMag.o   softfloat/f64_le.o                 softfloat/s_commonNaNToF32UI.o       softfloat/s_roundPackToF32.o \
	softfloat/f128_eq.o                softfloat/f16_to_i64.o            softfloat/f64_le_quiet.o           softfloat/s_commonNaNToF64UI.o       softfloat/s_roundPackToF64.o \
	softfloat/f128_eq_signaling.o      softfloat/f16_to_i64_r_minMag.o   softfloat/f64_lt.o                 softfloat/s_compare128M.o            softfloat/s_roundPackToI32.o \
	softfloat/f128_isSignalingNaN.o    softfloat/f16_to_i8.o             softfloat/f64_lt_quiet.o           softfloat/s_compare96M.o             softfloat/s_roundPackToI64.o \
	softfloat/f128_le.o                softfloat/f16_to_ui16.o           softfloat/f64_mul.o                softfloat/s_countLeadingZeros16.o    softfloat/s_roundPackToUI32.o \
	softfloat/f128_le_quiet.o          softfloat/f16_to_ui32.o           softfloat/f64_mulAdd.o             softfloat/s_countLeadingZeros32.o    softfloat/s_roundPackToUI64.o \
	softfloat/f128_lt.o                softfloat/f16_to_ui32_r_minMag.o  softfloat/f64_rem.o                softfloat/s_countLeadingZeros64.o    softfloat/s_roundToI32.o \
	softfloat/f128_lt_quiet.o          softfloat/f16_to_ui64.o           softfloat/f64_roundToInt.o         softfloat/s_countLeadingZeros8.o     softfloat/s_roundToI64.o \
	softfloat/f128_mul.o               softfloat/f16_to_ui64_r_minMag.o  softfloat/f64_sqrt.o               softfloat/s_eq128.o                  softfloat/s_roundToUI32.o \
	softfloat/f128_mulAdd.o            softfloat/f16_to_ui8.o            softfloat/f64_sub.o                softfloat/s_f128UIToCommonNaN.o      softfloat/s_roundToUI64.o \
	softfloat/f128_rem.o               softfloat/f32_add.o               softfloat/f64_to_f128.o            softfloat/s_f16UIToCommonNaN.o       softfloat/s_shiftRightJam128.o \
	softfloat/f128_roundToInt.o        softfloat/f32_classify.o          softfloat/f64_to_f16.o             softfloat/s_f32UIToCommonNaN.o       softfloat/s_shiftRightJam128Extra.o \
	softfloat/f128_sqrt.o              softfloat/f32_div.o               softfloat/f64_to_f32.o             softfloat/s_f64UIToCommonNaN.o       softfloat/s_shiftRightJam256M.o \
	softfloat/f128_sub.o               softfloat/f32_eq.o                softfloat/f64_to_i32.o             softfloat/s_le128.o                  softfloat/s_shiftRightJam32.o \
	softfloat/f128_to_f16.o            softfloat/f32_eq_signaling.o      softfloat/f64_to_i32_r_minMag.o    softfloat/s_lt128.o                  softfloat/s_shiftRightJam64.o \
	softfloat/f128_to_f32.o            softfloat/f32_isSignalingNaN.o    softfloat/f64_to_i64.o             softfloat/s_mul128By32.o             softfloat/s_shiftRightJam64Extra.o \
	softfloat/f128_to_f64.o            softfloat/f32_le.o                softfloat/f64_to_i64_r_minMag.o    softfloat/s_mul128MTo256M.o          softfloat/s_shortShiftLeft128.o \
	softfloat/f128_to_i32.o            softfloat/f32_le_quiet.o          softfloat/f64_to_ui32.o            softfloat/s_mul128To256M.o           softfloat/s_shortShiftLeft64To96M.o \
	softfloat/f128_to_i32_r_minMag.o   softfloat/f32_lt.o                softfloat/f64_to_ui32_r_minMag.o   softfloat/s_mul64ByShifted32To128.o  softfloat/s_shortShiftRight128.o \
	softfloat/f128_to_i64.o            softfloat/f32_lt_quiet.o          softfloat/f64_to_ui64.o            softfloat/s_mul64To128.o             softfloat/s_shortShiftRightExtendM.o \
	softfloat/f128_to_i64_r_minMag.o   softfloat/f32_mul.o               softfloat/f64_to_ui64_r_minMag.o   softfloat/s_mul64To128M.o            softfloat/s_shortShiftRightJam128.o \
	softfloat/f128_to_ui32.o           softfloat/f32_mulAdd.o            softfloat/fall_maxmin.o            softfloat/s_mulAddF128.o             softfloat/s_shortShiftRightJam128Extra.o \
	softfloat/f128_to_ui32_r_minMag.o  softfloat/f32_rem.o               softfloat/fall_reciprocal.o        softfloat/s_mulAddF16.o              softfloat/s_shortShiftRightJam64.o \
	softfloat/f128_to_ui64.o           softfloat/f32_roundToInt.o        softfloat/i32_to_f128.o            softfloat/s_mulAddF32.o              softfloat/s_shortShiftRightJam64Extra.o \
	softfloat/f128_to_ui64_r_minMag.o  softfloat/f32_sqrt.o              softfloat/i32_to_f16.o             softfloat/s_mulAddF64.o              softfloat/s_shortShiftRightM.o \
	softfloat/f16_add.o                softfloat/f32_sub.o               softfloat/i32_to_f32.o             softfloat/s_negXM.o                  softfloat/s_sub128.o \
	softfloat/f16_classify.o           softfloat/f32_to_bf16.o           softfloat/i32_to_f64.o             softfloat/s_normRoundPackToF128.o    softfloat/s_sub1XM.o \
	softfloat/f16_div.o                softfloat/f32_to_f128.o           softfloat/i64_to_f128.o            softfloat/s_normRoundPackToF16.o     softfloat/s_sub256M.o \
	softfloat/f16_eq.o                 softfloat/f32_to_f16.o            softfloat/i64_to_f16.o             softfloat/s_normRoundPackToF32.o     softfloat/s_subM.o \
	softfloat/f16_eq_signaling.o       softfloat/f32_to_f64.o            softfloat/i64_to_f32.o             softfloat/s_normRoundPackToF64.o     softfloat/s_subMagsF128.o \
	softfloat/f16_isSignalingNaN.o     softfloat/f32_to_i16.o            softfloat/i64_to_f64.o             softfloat/s_normSubnormalF128Sig.o   softfloat/s_subMagsF16.o \
	softfloat/f16_le.o                 softfloat/f32_to_i32.o            softfloat/s_add128.o               softfloat/s_normSubnormalF16Sig.o    softfloat/s_subMagsF32.o \
	softfloat/f16_le_quiet.o           softfloat/f32_to_i32_r_minMag.o   softfloat/s_add256M.o              softfloat/s_normSubnormalF32Sig.o    softfloat/s_subMagsF64.o \
	softfloat/f16_lt.o                 softfloat/f32_to_i64.o            softfloat/s_addCarryM.o            softfloat/s_normSubnormalF64Sig.o    softfloat/softfloat_raiseFlags.o \
	softfloat/f16_lt_quiet.o           softfloat/f32_to_i64_r_minMag.o   softfloat/s_addComplCarryM.o       softfloat/s_propagateNaNF128UI.o     softfloat/softfloat_state.o \
	softfloat/f16_mul.o                softfloat/f32_to_ui16.o           softfloat/s_addM.o                 softfloat/s_propagateNaNF16UI.o      softfloat/ui32_to_f128.o \
	softfloat/f16_mulAdd.o             softfloat/f32_to_ui32.o           softfloat/s_addMagsF128.o          softfloat/s_propagateNaNF32UI.o      softfloat/ui32_to_f16.o \
	softfloat/f16_rem.o                softfloat/f32_to_ui32_r_minMag.o  softfloat/s_addMagsF16.o           softfloat/s_propagateNaNF64UI.o      softfloat/ui32_to_f32.o \
	softfloat/f16_roundToInt.o         softfloat/f32_to_ui64.o           softfloat/s_addMagsF32.o           softfloat/s_remStepMBy32.o           softfloat/ui32_to_f64.o \
	softfloat/f16_sqrt.o               softfloat/f32_to_ui64_r_minMag.o  softfloat/s_addMagsF64.o           softfloat/s_roundMToI64.o            softfloat/ui64_to_f128.o \
	softfloat/f16_sub.o                softfloat/f64_add.o               softfloat/s_approxRecip32_1.o      softfloat/s_roundMToUI64.o           softfloat/ui64_to_f16.o \
	softfloat/f16_to_f128.o            softfloat/f64_classify.o          softfloat/s_approxRecipSqrt32_1.o  softfloat/s_roundPackMToI64.o        softfloat/ui64_to_f32.o \
	softfloat/f16_to_f32.o             softfloat/f64_div.o               softfloat/s_approxRecipSqrt_1Ks.o  softfloat/s_roundPackMToUI64.o       softfloat/ui64_to_f64.o

all: $(objs)
	 g++ -g -o perf_sim.exe $(objs)
	 

perf_sim.o: perf_sim.cpp
			g++ -c perf_sim.cpp -g

cachesim.o: cachesim.cc
			g++ -c cachesim.cc -g

cfg.o:  cfg.cc
		g++ -c cfg.cc -g

csrs.o:  csrs.cc
		g++ -c csrs.cc -g

disasm.o:  disasm.cc
		g++ -c disasm.cc -g

isa_parser.o:  isa_parser.cc
		g++ -c isa_parser.cc -g

extension.o: extension.cc
				g++ -c extension.cc -g

extensions.o: extensions.cc
				g++ -c extensions.cc -g

triggers.o:  triggers.cc
		g++ -c triggers.cc -g

vector_unit.o:  vector_unit.cc
		g++ -c vector_unit.cc -g

mmu.o:  mmu.cc
		g++ -c mmu.cc -g

debug_module.o:  debug_module.cc
		g++ -c debug_module.cc -g

devices.o:  devices.cc
		g++ -c devices.cc -g

processor.o:  processor.cc
		g++ -c processor.cc -g

sim.o:  sim.cc
		g++ -c sim.cc -g

rom.o: 	rom.cc
		g++ -c rom.cc -g

dts.o:  dts.cc
		g++ -c dts.cc -g

remote_bitbang.o: remote_bitbang.cc
					g++ -c remote_bitbang.cc -g
		
jtag_dtm.o: jtag_dtm.cc
			g++ -c jtag_dtm.cc -g

# socketif.o: socketif.cc
# 			g++ -c socketif.cc -g

insns/add.o: insns/add.cc
		g++ -c insns/add.cc -g

insns/addi.o: insns/addi.cc
		g++ -c insns/addi.cc -g

fdt.o: fdt/fdt.c
			gcc -c fdt/fdt.c -g

fdt_addresses.o: fdt/fdt_addresses.c
			gcc -c fdt/fdt_addresses.c -g

fdt_empty_tree.o: fdt/fdt_empty_tree.c
			gcc -c fdt/fdt_empty_tree.c -g

fdt_overlay.o: fdt/fdt_overlay.c
			gcc -c fdt/fdt_overlay.c -g

fdt_ro.o: fdt/fdt_ro.c
			gcc -c fdt/fdt_ro.c -g

fdt_rw.o: fdt/fdt_rw.c
			gcc -c fdt/fdt_rw.c -g

fdt_strerror.o: fdt/fdt_strerror.c
			gcc -c fdt/fdt_strerror.c -g

fdt_sw.o: fdt/fdt_sw.c
			gcc -c fdt/fdt_sw.c -g

fdt_wip.o: fdt/fdt_wip.c
			gcc -c fdt/fdt_wip.c -g

context.o: fesvr/context.cc
			gcc -c fesvr/context.cc -g

device.o: fesvr/device.cc
			gcc -c fesvr/device.cc -g

dtm.o: fesvr/dtm.cc
			gcc -c fesvr/dtm.cc -g

dummy.o: fesvr/dummy.cc
			gcc -c fesvr/dummy.cc -g

# elf2hex.o: fesvr/elf2hex.cc
# 			gcc -c fesvr/elf2hex.cc -g

elfloader.o: fesvr/elfloader.cc
			gcc -c fesvr/elfloader.cc -g

htif.o: fesvr/htif.cc
			gcc -c fesvr/htif.cc -g

htif_hexwriter.o: fesvr/htif_hexwriter.cc
			gcc -c fesvr/htif_hexwriter.cc -g

htif_pthread.o: fesvr/htif_pthread.cc
			gcc -c fesvr/htif_pthread.cc -g

memif.o: fesvr/memif.cc
			gcc -c fesvr/memif.cc -g

option_parser.o: fesvr/option_parser.cc
			gcc -c fesvr/option_parser.cc -g

rfb.o: fesvr/rfb.cc
			gcc -c fesvr/rfb.cc -g

syscall.o: fesvr/syscall.cc
			gcc -c fesvr/syscall.cc -g

term.o: fesvr/term.cc
			gcc -c fesvr/term.cc -g

tsi.o: fesvr/tsi.cc
			gcc -c fesvr/tsi.cc -g

interactive.o: interactive.cc
				g++ -c interactive.cc -g

decoder.o:
		g++ -c arch/decoder.cpp
execute.o:
		g++ -c arch/execute.cpp
fetch.o:
		g++ -c arch/fetch.cpp
scoreboard.o:
		g++ -c arch/scoreboard.cpp


s_subMagsF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_subMagsF32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_subMagsF64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
softfloat_raiseFlags.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
softfloat_state.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui32_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui32_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui32_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui32_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui64_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui64_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui64_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
ui64_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundToI32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundToI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundToUI32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundToUI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam128Extra.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam256M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shiftRightJam64Extra.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftLeft128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftLeft64To96M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRight128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightExtendM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightJam128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightJam128Extra.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightJam64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightJam64Extra.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_shortShiftRightM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_sub128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_sub1XM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_sub256M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_subM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_subMagsF128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mulAddF64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_negXM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normRoundPackToF128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normRoundPackToF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normRoundPackToF32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normRoundPackToF64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normSubnormalF128Sig.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normSubnormalF16Sig.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normSubnormalF32Sig.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_normSubnormalF64Sig.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_propagateNaNF128UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_propagateNaNF16UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_propagateNaNF32UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_propagateNaNF64UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_remStepMBy32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundMToI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundMToUI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackMToI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackMToUI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToBF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToF128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToF32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToF64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToI32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToUI32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_roundPackToUI64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_approxRecipSqrt32_1.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_approxRecipSqrt_1Ks.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_approxRecip_1Ks.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_commonNaNToF128UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_commonNaNToF16UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_commonNaNToF32UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_commonNaNToF64UI.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_compare128M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_compare96M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_countLeadingZeros16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_countLeadingZeros32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_countLeadingZeros64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_countLeadingZeros8.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_eq128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_f128UIToCommonNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_f16UIToCommonNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_f32UIToCommonNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_f64UIToCommonNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_le128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_lt128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul128By32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul128MTo256M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul128To256M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul64ByShifted32To128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul64To128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mul64To128M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mulAddF128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mulAddF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_mulAddF32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i32_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i32_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i64_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i64_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i64_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i64_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_add128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_add256M.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addCarryM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addComplCarryM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addM.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addMagsF128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addMagsF16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addMagsF32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_addMagsF64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
s_approxRecip32_1.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_eq.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_eq_signaling.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_isSignalingNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_le.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_le_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_lt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_lt_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_mul.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_mulAdd.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_rem.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_roundToInt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_sqrt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_sub.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_i32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_i32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_i64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_i64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_ui32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_ui32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_ui64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_to_ui64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
fall_maxmin.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
fall_reciprocal.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i32_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
i32_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_lt_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_mul.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_mulAdd.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_rem.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_roundToInt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_sqrt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_sub.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_bf16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_i16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_i32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_i32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_i64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_i64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_ui16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_ui32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_ui32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_ui64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_to_ui64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_add.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_classify.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f64_div.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_sub.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_f128.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_i8.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_to_ui8.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_add.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_classify.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_div.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_eq.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_eq_signaling.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_isSignalingNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_le.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_le_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f32_lt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_f64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_i32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_i32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_i64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_i64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_ui32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_ui32_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_ui64.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_ui64_r_minMag.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_add.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_classify.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_div.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_eq.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_eq_signaling.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_isSignalingNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_le.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_le_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_lt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_lt_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_mul.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_mulAdd.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_rem.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_roundToInt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f16_sqrt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_lt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_lt_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_mul.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_mulAdd.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_rem.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_roundToInt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_sqrt.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_sub.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_to_f16.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_classify.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_div.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_eq.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_eq_signaling.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_isSignalingNaN.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_le.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_le_quiet.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
bf16_to_f32.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
f128_add.o: softfloat/bf16_to_f32.c
		gcc -c softfloat/bf16_to_f32.c
			
clean:
	rm *.o
	mv perf_sim.exe old_sim.exe