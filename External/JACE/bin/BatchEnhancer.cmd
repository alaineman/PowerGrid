@echo off
java -classpath "%JACE_HOME%\lib\asm-1.5.1.jar";"%JACE_HOME%\lib\asm-attrs-1.5.1.jar";"%JACE_HOME%\lib\bcel.jar";"%JACE_HOME%\lib\jace.jar";"%JACE_HOME%\lib\regex.jar";"%JACE_HOME%\lib\retroweaver.jar" jace.peergen.BatchEnhancer %*
@echo on
