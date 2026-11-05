"""
Adam Welker     Utah Robotics Center       NOV 26

WRITTEN BY CLAUDE SONNET 5.5

Everest CORE (Novanta / Summit servo drive) error codes.

Source: https://drives.novantamotion.com/eve-core/error-management
(page last modified 2021-07-07 per its metadata)

Warnings are reported as the base error code OR'd with bit 28 (0x10000000).
Use decode_error() to handle that.



"""

WARNING_BIT = 0x10000000

# ---------------------------------------------------------------------------
# Operation errors
# ---------------------------------------------------------------------------
OPERATION_ERRORS = {
    0x00000000: "No error",
    0x00001001: "Communications watchdog error",
    0x00002280: "Over-current detected (internal drive limit)",
    0x00002281: "Faulty gate driver",
    0x00002282: "Current A sensing reached upper saturation limit",
    0x00002283: "Current A sensing reached lower saturation limit",
    0x00002284: "Current B sensing reached upper saturation limit",
    0x00002285: "Current B sensing reached lower saturation limit",
    0x00002286: "Current C sensing reached upper saturation limit",
    0x00002287: "Current C sensing reached lower saturation limit",
    0x00002288: "User I2T limit detected",
    0x00002289: "Over-current detected (user limit) without current control",
    0x0000228A: "System I2T detected",
    0x0000228B: "Derating without current control",
    0x0000228C: "Current sensor calibration error",
    0x00002301: "Brake over-current",
    0x00002302: "Brake tracking error",
    0x00003210: "Over-voltage detected (internal drive limit)",
    0x00003211: "Over-voltage detected (redundant internal drive limit)",
    0x00003221: "Under-voltage detected (internal drive limit)",
    0x00003231: "Over-voltage detected (user limit)",
    0x00003241: "Under-voltage detected (user limit)",
    0x00003280: "STO is enabled",
    0x00003281: "STO supply fault",
    0x00003282: "STO abnormal fault",
    0x00003283: "STO active in operation enabled",
    0x00003290: "Input stage problem",
    0x00004300: "Over-temperature detected (internal drive limit)",
    0x00004301: "Under-temperature detected (internal drive limit)",
    0x00004303: "Over-temperature detected (user limit)",
    0x00004304: "Under-temperature detected (user limit)",
    0x00004305: "Wrong ADC measurements detection",
    0x00004400: "Motor over temperature detected (sensor 1)",
    0x00004401: "Motor over temperature detected (sensor 2)",
    0x00004500: "External fault",
    0x00007370: "Halls sequence error",
    0x00007371: "Halls combination error",
    0x00007372: "Feedback runaway error",
    0x0000737E: "Serial 1 encoder - Disconnection or frame overlap",
    0x0000737F: "Serial 2 encoder - Disconnection or frame overlap",
    0x00007380: "Serial 1 encoder - Too many incorrect invalid position flags detected in SSI / BiSS-C readings",
    0x00007381: "Serial 1 encoder - BiSS-C warning bit active",
    0x00007382: "Serial 1 encoder - Too many incorrect CRC checks in SSI / BiSS-C readings",
    0x00007384: "Serial 1 encoder - Error bit active without exceeding error tolerance",
    0x00007385: "Position out of limits out of position modes",
    0x00007386: "Velocity out of limits out of velocity or position modes",
    0x00007387: "In a position mode, following error overcomes the position following error window",
    0x00007388: "In a velocity mode, following error overcomes the velocity following error window",
    0x00007389: "Angle integrity check 1 detected",
    0x0000738A: "Angle integrity check 2 detected",
    0x0000738C: "Position out of limits in position mode",
    0x00007390: "Interpolation time is too small when PVT is enabled",
    0x00007391: "Profiler parameters not valid (they should all have positive values)",
    0x00007395: "Profiler end velocity not reachable",
    0x0000739A: "The electrical velocity limit has been exceeded",
    0x0000739B: "User over temperature warning threshold exceeded",
    0x0000739C: "User under temperature warning threshold exceeded",
    0x0000739D: "Serial 2 encoder - Too many incorrect invalid position flags detected in SSI / BiSS-C readings",
    0x0000739E: "Serial 2 encoder - BiSS-C warning bit active",
    0x0000739F: "Serial 2 encoder - Too many incorrect CRC checks in SSI / BiSS-C readings",
    0x000073A0: "Serial 2 encoder - Error bit active without exceeding error tolerance",
    0x000073A1: "Serial 1 encoder - SSI FR mode incorrect frame start",
    0x000073A2: "Serial 2 encoder - SSI FR mode incorrect frame start",
    0x000073A5: "Current imbalance detected",
}

# ---------------------------------------------------------------------------
# Register errors (configuration / register access, no reaction)
# ---------------------------------------------------------------------------
REGISTER_ERRORS = {
    0x0000738B: "Trapezoidal commutation without digital halls not allowed",
    0x00007400: "Unsupported synchronization method",
    0x00007500: "Number of active feedbacks is higher than allowed",
    0x00007503: "Access unsupported in the current state",
    0x00007504: "Access unsupported because of local control",
    0x05040000: "COMKIT Timeout. CORE device is not properly connected",
    0x06010000: "Incorrect access type",
    0x06020000: "Object does not exist",
    0x06040041: "Object isn't cyclic mappable as requested",
    0x06040042: "Cyclic mapping is too large",
    0x06070010: "Mapped cyclic register size is wrong",
    0x06090011: "Sub-Index does not exist",
    0x060A0000: "Unsupported value introduced in register",
    0x08000000: "Read / Write operation not executed",
    0x08010000: "Cyclic mapping key is wrong",
    0x08010010: "Communication state is unreachable",
    0x08010020: "Communication setting is not modifiable in the current state",
    0x08010030: "Invalid command",
    0x08010040: "CRC error",
}

# Combined lookup
ERROR_CODES = {**OPERATION_ERRORS, **REGISTER_ERRORS}

# ---------------------------------------------------------------------------
# Default severity of operation errors, where the page lists something other
# than the usual "Fault - Power stage shutdown".
# ---------------------------------------------------------------------------
NON_DEFAULT_SEVERITY = {
    0x00002288: "Warning - Do nothing",
    0x00003282: "Critical - Power stage shutdown",
    0x00007381: "Warning",
    0x00007384: "Warning",
    0x00007395: "Warning",
    0x0000739B: "Warning",
    0x0000739C: "Warning",
    0x0000739E: "Warning",
    0x000073A0: "Warning",
}


def decode_error(raw: int) -> str:
    """
    Convert a raw 32-bit error ID into a human-readable string.

    Handles the warning flag (bit 28). Unknown codes are reported in hex
    rather than raising, so it is safe to call on live telemetry.
    """
    raw = int(raw) & 0xFFFFFFFF
    is_warning = bool(raw & WARNING_BIT)
    code = raw & ~WARNING_BIT

    desc = ERROR_CODES.get(code, f"Unknown error code 0x{code:08X}")
    if code == 0 and not is_warning:
        return desc
    if code in REGISTER_ERRORS:
        prefix = "INFO"  # register access errors never trigger a reaction
    else:
        prefix = "WARNING" if is_warning else "FAULT"
    return f"[{prefix}] 0x{code:08X}: {desc}"


if __name__ == "__main__":
    for value in (0x00000000, 0x00002280, 0x10002288, 0x00007387, 0x08010040, 0x12345678):
        print(f"0x{value:08X} -> {decode_error(value)}")
