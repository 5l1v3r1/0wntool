void Reset(void)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  
  puVar3 = DAT_00000318;
  puVar2 = (undefined8 *)FUN_00005ec0(0);
  if (puVar3 != puVar2) {
    lVar4 = DAT_00000320 - (longlong)DAT_00000318;
    do {
      uVar5 = puVar2[1];
      *puVar3 = *puVar2;
      puVar3[1] = uVar5;
      puVar2 = puVar2 + 2;
      puVar3 = puVar3 + 2;
      lVar4 = lVar4 + -0x10;
    } while (lVar4 != 0);
    return;
  }
  uVar1 = cRead_8(daif);
  cWrite_8(daif,uVar1 | 0x3c0);
  cWrite_8(vbar_el3,0xb000);
  puVar3 = (undefined8 *)(PTR_DAT_00000360 + (longlong)DAT_00000358);
  puVar2 = DAT_00000358;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar6 = DAT_00000340;
    puVar2 = puVar2 + 2;
  } while (puVar2 != puVar3);
  cWrite_8(spsel,0);
  _DAT_80080000 = DAT_00000358 + 0xa00;
  puVar2 = (undefined8 *)(DAT_00000330 + 0xfffU & 0xfffffffffffff000);
  puVar3 = DAT_00000338;
  if (puVar2 != DAT_00000338) {
    do {
      uVar5 = puVar2[1];
      *puVar3 = *puVar2;
      puVar3[1] = uVar5;
      puVar2 = puVar2 + 2;
      puVar3 = puVar3 + 2;
    } while (puVar3 != puVar6);
  }
  puVar3 = DAT_00000350;
  puVar2 = (undefined8 *)((ulonglong)DAT_00000350 & 0xfffffffffffffff0);
  puVar6 = DAT_00000348;
  do {
    puVar6 = puVar6 + 2;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6 = puVar6;
  } while (puVar6 != puVar2);
  while (puVar3 != puVar2) {
    puVar2 = (undefined8 *)((longlong)puVar6 + 4);
    *(undefined4 *)puVar6 = 0;
    puVar6 = puVar2;
  }
  return;
}
