
DEFINE_SPEC(EquipmentComponentSpec, "GenericEquipment.EquipmentCore.EquipmentComponentSpec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

void EquipmentComponentSpec::Define()
{
	// TODO: Equipment component tests

	Describe("Equipment Component", [this]()
	{
		It("should start with empty equipment", [this]()
		{
			// TestEqual("Equipments", )
		});
	});
}
