/* Entry Point */
ENTRY(reset_handler)

MEMORY {
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 96K
}

/* end of RAM */
_estack = 0x20017FFF;

/* Define output sections */
SECTIONS {
  . = 0x08000000;
  .text : {
    * (.text);
  }
  flash_sdata = .;

  . = 0x20000000;
  ram_sdata = .;
  .data : AT (flash_sdata) {
    * (.data);
  }
  ram_edata = .;
  data_size = ram_edata - ram_sdata;
}
