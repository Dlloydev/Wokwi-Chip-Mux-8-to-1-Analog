# Wokwi-Chip-Mux-8-to-1-Analog

## Description

This chip connects 1 of 8 digital inputs to a single output. When Select = 0 (default), the output is disabled (0). The LED output (PWM) is used for diagnostic purposes.

![image](https://user-images.githubusercontent.com/63488701/217681693-d5dd3b26-01c5-478c-a3de-f72dfa91840f.png)

| Select | A8   | A7   | A6   | A5   | A4   | A3   | A2   | A1   | OUT  | LED (PWM) |
| ------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | --------- |
| 0      | X    | X    | X    | X    | X    | X    | X    | X    | 0    | 0         |
| 1      | X    | X    | X    | X    | X    | X    | X    | A1   | A1   | A1        |
| 2      | X    | X    | X    | X    | X    | X    | A2   | X    | A2   | A2        |
| 3      | X    | X    | X    | X    | X    | A3   | X    | X    | A3   | A3        |
| 4      | X    | X    | X    | X    | A4   | X    | X    | X    | A4   | A4        |
| 5      | X    | X    | X    | A5   | X    | X    | X    | X    | A5   | A5        |
| 6      | X    | X    | A6   | X    | X    | X    | X    | X    | A6   | A6        |
| 7      | X    | A7   | X    | X    | X    | X    | X    | X    | A7   | A7        |
| 8      | A8   | X    | X    | X    | X    | X    | X    | X    | A8   | A8        |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-mux-8-to-1-analog": "github:Dlloydev/Wokwi-Chip-Mux-8-to-1-Analog@1.0.0"
  }
```

Then, add the chip to your circuit by adding a `chip-mux-8-to-1-analog` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-mux-8-to-1-analog", "id": "chip-mux-8-to-1-analog1" }
  },
```

The actual source code for the chip lives in [src/main.c](https://github.com/Dlloydev/Wokwi-Chip-Mux-8-to-1-Analog/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-Mux-8-to-1-Analog/blob/main/chip.json).

## Example

[![Wokwi_badge](https://user-images.githubusercontent.com/63488701/212449119-a8510897-c860-4545-8c1a-794169547ba1.svg)](https://wokwi.com/projects/356126395269864449) 8 to 1 Analog Multiplexer Example

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/Dlloydev/Wokwi-Chip-Mux-8-to-1-Analog/blob/main/LICENSE) file for more details.
