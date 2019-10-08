import sys, usb, json, dfu, usbexec, checkm8, hashlib

first_header = """
0wntool, written by Dylan Moore. Thank you axi0mX for checkm8!
You need libusb1 & pyusb installed, libusb1 on Windows will be a pain.
NO WARRANTY, if you f your device up its not my problem.
Read LICENSE for info on license stuff... (GNU v3)
"""

supported_devices = ['CPID:8947',
                    'CPID:8950',
                    'CPID:8955',
                    'CPID:8960',
                    'CPID:8002',
                    'CPID:8004',
                    'CPID:8010',
                    'CPID:8011',
                    'CPID:8015']

if __name__ == "__main__":
    print(first_header)

    device = dfu.acquire_device()
    serial_number = device.serial_number
    dfu.release_device(device)

    # TODO: Clean this segment up.
    supported = False
    for device in supported_devices:
        if device in serial_number:
            supported = True
            break

    if not supported:
        print("Your device is not supported, sorry boss.")
        sys.exit(0)

    if "PWND:[checkm8]" in serial_number:
        print("Your device has already been exploited.")
    else:
        print("Running checkm8 exploit.")
        checkm8.exploit()

    # Dump SecureROM for backup.
    print("Dumping SecureROM, you better back it up when this process is completed.")

    pwned = usbexec.PwnedUSBDevice()
    securerom = pwned.read_memory(pwned.platform.rom_base, pwned.platform.rom_size)

    if hashlib.sha1(securerom).hexdigest() != pwned.platform.rom_sha1:
        print('ERROR: SecureROM was dumped, but the SHA1 hash does not match. Exiting.')
        sys.exit(1)

    chip    = (securerom[0x200:0x240].split(b' ')[2][:-1]).decode("utf-8")
    kind    = (securerom[0x240:0x280].split(b'\0')[0]).decode("utf-8")
    version = (securerom[0x280:0x2C0].split(b'\0')[0][6:]).decode("utf-8")

    with open(f"SecureROM-{chip}-{kind}-{version}.dump", "wb") as f:
        f.write(securerom)

    print("SecureROM dumped.")