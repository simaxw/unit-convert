function Component() {
}

Component.prototype.createOperations = function() {
  component.createOperations();

  if ( installer.value("os") === "win" ) {
    component.addOperation(
      "CreateShortcut",
      "@TargetDir@/convert.exe",
      "@StartMenuDir@/Convert.lnk"
    );
  }
}