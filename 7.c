void Reset(void)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  puVar3 = DAT_00000318;
  puVar2 = (undefined8 *)FUN_00007bd8(0);
  if (puVar3 != puVar2) {
    lVar4 = DAT_00000320 - (longlong)DAT_00000318;
    do {
      uVar6 = puVar2[1];
      *puVar3 = *puVar2;
      puVar3[1] = uVar6;
      lVar4 = lVar4 + -0x10;
      puVar2 = puVar2 + 2;
      puVar3 = puVar3 + 2;
    } while (lVar4 != 0);
    return;
  }
  uVar1 = cRead_8(daif);
  cWrite_8(daif,uVar1 | 0x3c0);
  cWrite_8(vbar_el1,0xc000);
  puVar2 = (undefined8 *)(DAT_00000360 + (longlong)DAT_00000358);
  puVar3 = DAT_00000358;
  do {
    puVar8 = puVar3 + 2;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3 = puVar8;
  } while (puVar8 != puVar2);
  puVar2 = (undefined8 *)(PTR_LAB_00000370 + (longlong)DAT_00000368);
  puVar3 = DAT_00000368;
  do {
    puVar5 = puVar3 + 2;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar8 = DAT_00000340;
    puVar3 = puVar5;
  } while (puVar5 != puVar2);
  cWrite_8(spsel,0);
  _DAT_80080000 = DAT_00000358 + 0x800;
  puVar2 = (undefined8 *)(DAT_00000330 + 0x3fffU & 0xffffffffffffc000);
  puVar3 = DAT_00000338;
  if (puVar2 != DAT_00000338) {
    do {
      uVar6 = puVar2[1];
      puVar5 = puVar3 + 2;
      *puVar3 = *puVar2;
      puVar3[1] = uVar6;
      puVar2 = puVar2 + 2;
      puVar3 = puVar5;
    } while (puVar5 != puVar8);
  }
  puVar3 = DAT_00000350;
  puVar2 = (undefined8 *)((ulonglong)DAT_00000350 & 0xfffffffffffffff0);
  puVar8 = DAT_00000348;
  do {
    puVar5 = puVar8 + 2;
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8 = puVar5;
  } while (puVar5 != puVar2);
  while (puVar3 != puVar2) {
    puVar2 = (undefined8 *)((longlong)puVar5 + 4);
    *(undefined4 *)puVar5 = 0;
    puVar5 = puVar2;
  }
  puVar2 = DAT_00000378 + 0x800;
  puVar3 = DAT_00000378;
  do {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar9 = puVar3 + 8;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar8 = DAT_00000388;
    puVar5 = DAT_00000380;
    puVar7 = DAT_00000390;
    puVar3 = puVar9;
  } while (puVar9 != puVar2);
  do {
    puVar2 = puVar5 + 2;
    uVar6 = puVar5[1];
    *puVar7 = *puVar5;
    puVar7[1] = uVar6;
    puVar5 = puVar2;
    puVar7 = puVar7 + 2;
  } while (puVar2 < puVar8);
  return;
}
