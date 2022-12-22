void setup() {
  Serial.begin(9600);
  char *str = "ff00FF";
  int r, g, b;
  sscanf(str, "%02x%02x%02x", &r, &g, &b);
  Serial.print("rgb("); Serial.print(r); Serial.print(", "); Serial.print(g); Serial.print(", "); Serial.print(b); Serial.println(")");
  Serial.println(to16bits(r, g, b));
  //Serial.print("0x"); Serial.print(((r + 4) / 8) * 8); Serial.print(((g + 4) / 8) * 8); Serial.println(((b + 4) / 8) * 8);
}

void loop() {
  
}

int to16bits (int r, int g, int b)
{
  int ir = (r / 255.0f) * 31.0f + 0.5f;
  int ig = (g / 255.0f) * 63.0f + 0.5f;
  int ib = (b / 255.0f) * 31.0f + 0.5f;
  return (ir << 11) | (ig << 5) | ib;
}
