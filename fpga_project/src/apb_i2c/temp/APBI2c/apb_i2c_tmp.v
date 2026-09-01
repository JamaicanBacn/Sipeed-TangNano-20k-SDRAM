//Copyright (C)2014-2026 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//Tool Version: V1.9.12.03 (64-bit)
//IP Version: 1.0
//Part Number: GW2AR-LV18QN88C8/I7
//Device: GW2AR-18
//Created Time: Mon Aug 31 21:20:56 2026

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

	APB_I2C_Top your_instance_name(
		.i2c_int(i2c_int), //output i2c_int
		.paddr(paddr), //input [5:2] paddr
		.penable(penable), //input penable
		.prdata(prdata), //output [31:0] prdata
		.psel(psel), //input psel
		.pwdata(pwdata), //input [31:0] pwdata
		.pwrite(pwrite), //input pwrite
		.pready(pready), //output pready
		.pslverr(pslverr), //output pslverr
		.pclk(pclk), //input pclk
		.presetn(presetn), //input presetn
		.scl_o(scl_o), //output scl_o
		.sda_o(sda_o), //output sda_o
		.scl_i(scl_i), //input scl_i
		.sda_i(sda_i) //input sda_i
	);

//--------Copy end-------------------
