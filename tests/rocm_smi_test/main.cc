/*
 * =============================================================================
 *   ROC Runtime Conformance Release License
 * =============================================================================
 * The University of Illinois/NCSA
 * Open Source License (NCSA)
 *
 * Copyright (c) 2018, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Developed by:
 *
 *                 AMD Research and AMD ROC Software Development
 *
 *                 Advanced Micro Devices, Inc.
 *
 *                 www.amd.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimers.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimers in
 *    the documentation and/or other materials provided with the distribution.
 *  - Neither the names of <Name of Development Group, Name of Institution>,
 *    nor the names of its contributors may be used to endorse or promote
 *    products derived from this Software without specific prior written
 *    permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS WITH THE SOFTWARE.
 *
 */

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "rocm_smi/rocm_smi.h"
#include "gtest/gtest.h"
#include "rocm_smi_test/test_common.h"
#include "rocm_smi_test/test_base.h"
#include "functional/fan_read.h"
#include "functional/fan_read_write.h"
#include "functional/temp_read.h"
#include "functional/volt_freq_curv_read.h"
#include "functional/perf_level_read.h"
#include "functional/overdrive_read.h"
#include "functional/frequencies_read.h"
#include "functional/sys_info_read.h"
#include "functional/gpu_busy_read.h"
#include "functional/power_read.h"
#include "functional/overdrive_read_write.h"
#include "functional/perf_level_read_write.h"
#include "functional/frequencies_read_write.h"
#include "functional/pci_read_write.h"
#include "functional/power_read_write.h"
#include "functional/power_cap_read_write.h"
#include "functional/version_read.h"
#include "functional/err_cnt_read.h"
#include "functional/mem_util_read.h"
#include "functional/id_info_read.h"
#include "functional/perf_cntr_read_write.h"
#include "functional/process_info_read.h"

static RSMITstGlobals *sRSMIGlvalues = nullptr;

static void SetFlags(TestBase *test) {
  assert(sRSMIGlvalues != nullptr);

  test->set_verbosity(sRSMIGlvalues->verbosity);
  test->set_dont_fail(sRSMIGlvalues->dont_fail);
  test->set_init_options(sRSMIGlvalues->init_options);
}


static void RunCustomTestProlog(TestBase *test) {
  SetFlags(test);

  test->DisplayTestInfo();
  test->SetUp();
  test->Run();
  return;
}
static void RunCustomTestEpilog(TestBase *test) {
  test->DisplayResults();
  test->Close();
  return;
}

// If the test case one big test, you should use RunGenericTest()
// to run the test case. OTOH, if the test case consists of multiple
// functions to be run as separate tests, follow this pattern:
//   * RunCustomTestProlog(test)  // Run() should contain minimal code
//   * <insert call to actual test function within test case>
//   * RunCustomTestEpilog(test)
static void RunGenericTest(TestBase *test) {
  RunCustomTestProlog(test);
  RunCustomTestEpilog(test);
  return;
}

// TEST ENTRY TEMPLATE:
// TEST(rocrtst, Perf_<test name>) {
//  <Test Implementation class> <test_obj>;
//
//  // Copy and modify implementation of RunGenericTest() if you need to deviate
//  // from the standard pattern implemented there.
//  RunGenericTest(&<test_obj>);
// }
TEST(rsmitstReadOnly, TestVersionRead) {
  TestVersionRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, FanRead) {
  TestFanRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, FanReadWrite) {
  TestFanReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TempRead) {
  TestTempRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestVoltCurvRead) {
  TestVoltCurvRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestPerfLevelRead) {
  TestPerfLevelRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestPerfLevelReadWrite) {
  TestPerfLevelReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestOverdriveRead) {
  TestOverdriveRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestOverdriveReadWrite) {
  TestOverdriveReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestFrequenciesRead) {
  TestFrequenciesRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestFrequenciesReadWrite) {
  TestFrequenciesReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestPciReadWrite) {
  TestPciReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestSysInfoRead) {
  TestSysInfoRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestGPUBusyRead) {
  TestGPUBusyRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestPowerRead) {
  TestPowerRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestPowerReadWrite) {
  TestPowerReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestPowerCapReadWrite) {
  TestPowerCapReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestErrCntRead) {
  TestErrCntRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestMemUtilRead) {
  TestMemUtilRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestIdInfoRead) {
  TestIdInfoRead tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadWrite, TestPerfCntrReadWrite) {
  TestPerfCntrReadWrite tst;
  RunGenericTest(&tst);
}
TEST(rsmitstReadOnly, TestProcInfoRead) {
  TestProcInfoRead tst;
  RunGenericTest(&tst);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  RSMITstGlobals settings;

  // Set some default values
  settings.verbosity = 1;
  settings.monitor_verbosity = 1;
  settings.num_iterations = 1;
  settings.dont_fail = false;
  settings.init_options = 0;

  if (ProcessCmdline(&settings, argc, argv)) {
    return 1;
  }

  int ret = 0;
  sRSMIGlvalues = &settings;
  ret = RUN_ALL_TESTS();

  if (ret) {
    return ret;
  }

  settings.init_options = RSMI_INIT_FLAG_ALL_GPUS;

  std::cout << "****************************************" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "Re-running tests with init options: " << std::hex <<
                                    settings.init_options << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "****************************************" << std::endl;
  std::cout << "****************************************" << std::endl;
  settings.init_options = RSMI_INIT_FLAG_ALL_GPUS;
  return RUN_ALL_TESTS();
}
