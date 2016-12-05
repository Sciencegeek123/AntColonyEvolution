#include "ant/ant.h"
#include "utils/utils.h"
#include <iostream>
#include "ai/ai_enums.h"

bool Ant::EvaluateAction(OutputActions action, int iteration)
{
  switch (action)
  {
  case OutputActions::ADecrementPDMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_a = memory_decaying_a < GC->PersonalMemoryX_Delta
                            ? 0
                            : memory_decaying_a - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPDMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_a = memory_decaying_a < GC->PersonalMemoryY_Delta
                            ? 0
                            : memory_decaying_a - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPDMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_a = memory_decaying_a + GC->PersonalMemoryX_Delta > 255
                            ? 255
                            : memory_decaying_a + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPDMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_a = memory_decaying_a + GC->PersonalMemoryY_Delta > 255
                            ? 255
                            : memory_decaying_a + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPDMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_b = memory_decaying_b < GC->PersonalMemoryX_Delta
                            ? 0
                            : memory_decaying_b - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPDMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_b = memory_decaying_b < GC->PersonalMemoryY_Delta
                            ? 0
                            : memory_decaying_b - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPDMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_b = memory_decaying_b + GC->PersonalMemoryX_Delta > 255
                            ? 255
                            : memory_decaying_b + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPDMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_b = memory_decaying_b + GC->PersonalMemoryY_Delta > 255
                            ? 255
                            : memory_decaying_b + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPDMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_c = memory_decaying_c < GC->PersonalMemoryX_Delta
                            ? 0
                            : memory_decaying_c - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPDMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_c = memory_decaying_c < GC->PersonalMemoryY_Delta
                            ? 0
                            : memory_decaying_c - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPDMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_c = memory_decaying_c + GC->PersonalMemoryX_Delta > 255
                            ? 255
                            : memory_decaying_c + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPDMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_c = memory_decaying_c + GC->PersonalMemoryY_Delta > 255
                            ? 255
                            : memory_decaying_c + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPDMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_d = memory_decaying_d < GC->PersonalMemoryX_Delta
                            ? 0
                            : memory_decaying_d - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPDMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_d = memory_decaying_d < GC->PersonalMemoryY_Delta
                            ? 0
                            : memory_decaying_d - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPDMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_d = memory_decaying_d + GC->PersonalMemoryX_Delta > 255
                            ? 255
                            : memory_decaying_d + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPDMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_decaying_d = memory_decaying_d + GC->PersonalMemoryY_Delta > 255
                            ? 255
                            : memory_decaying_d + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPSMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_a = memory_static_a < GC->PersonalMemoryX_Delta
                          ? 0
                          : memory_static_a - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPSMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_a = memory_static_a < GC->PersonalMemoryY_Delta
                          ? 0
                          : memory_static_a - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPSMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_a = memory_static_a + GC->PersonalMemoryX_Delta > 255
                          ? 255
                          : memory_static_a + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPSMA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_a = memory_static_a + GC->PersonalMemoryY_Delta > 255
                          ? 255
                          : memory_static_a + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPSMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_b = memory_static_b < GC->PersonalMemoryX_Delta
                          ? 0
                          : memory_static_b - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPSMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_b = memory_static_b < GC->PersonalMemoryY_Delta
                          ? 0
                          : memory_static_b - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPSMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_b = memory_static_b + GC->PersonalMemoryX_Delta > 255
                          ? 255
                          : memory_static_b + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPSMB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_b = memory_static_b + GC->PersonalMemoryY_Delta > 255
                          ? 255
                          : memory_static_b + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPSMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_c = memory_static_c < GC->PersonalMemoryX_Delta
                          ? 0
                          : memory_static_c - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPSMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_c = memory_static_c < GC->PersonalMemoryY_Delta
                          ? 0
                          : memory_static_c - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPSMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_c = memory_static_c + GC->PersonalMemoryX_Delta > 255
                          ? 255
                          : memory_static_c + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPSMC:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_c = memory_static_c + GC->PersonalMemoryY_Delta > 255
                          ? 255
                          : memory_static_c + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ADecrementPSMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_d = memory_static_d < GC->PersonalMemoryX_Delta
                          ? 0
                          : memory_static_d - GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BDecrementPSMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_d = memory_static_d < GC->PersonalMemoryY_Delta
                          ? 0
                          : memory_static_d - GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::AIncrementPSMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_d = memory_static_d + GC->PersonalMemoryX_Delta > 255
                          ? 255
                          : memory_static_d + GC->PersonalMemoryX_Delta;
    return true;
    break;
  }
  case OutputActions::BIncrementPSMD:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    memory_static_d = memory_static_d + GC->PersonalMemoryY_Delta > 255
                          ? 255
                          : memory_static_d + GC->PersonalMemoryY_Delta;
    return true;
    break;
  }
  case OutputActions::ResetPersonalTimerA:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    TimerA = iteration;
    return true;
    break;
  }
  case OutputActions::ResetPersonalTimerB:
  {
    if (!checkFoodDelta(-Settings.Action_PersonalMemoryChangeCost))
    {
      return false;
    }
    else
    {
      registerFoodDelta(-Settings.Action_PersonalMemoryChangeCost);
    }
    TimerB = iteration;
    return true;
    break;
  }
  default:
  {
    return false;
    break;
  }
  }
}