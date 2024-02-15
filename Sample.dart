class vga {
  String darVideo() {
    return "dando video en VGA";
  }
}

abstract class HDMI {
  String VideoHD() {
    return "Dando video en HD";
  }
}

class adapter extends vga implements HDMI {
  @override
  String VideoHD() {
    return " Convirtiendo video vga a HDMI";
  }
}

class PC {
  String SalidaVIDEO(HDMI hdmi) {
    return hdmi.VideoHD();
  }
}

void main() {
  PC pc = PC();

  vga VGA = vga();
  adapter Adapter = adapter();

  print("VGAA ${VGA.darVideo()}");
  print("Dando video ${pc.SalidaVIDEO(Adapter)}");
}
