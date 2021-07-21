<project xmlns="com.autoesl.autopilot.project" name="DNN" top="dnn">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow askAgain="false" name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../../dnn_testbench.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="DNN.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="inactive"/>
        <solution name="solution2" status="inactive"/>
        <solution name="solution3" status="inactive"/>
        <solution name="solution4" status="inactive"/>
        <solution name="ReLU1" status="inactive"/>
        <solution name="sigmoidH100" status="active"/>
    </solutions>
</project>

